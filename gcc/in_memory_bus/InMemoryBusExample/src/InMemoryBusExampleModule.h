/*
 * InMemoryBusExampleModule.h
 *
 *  Created on: 2 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUSEXAMPLEMODULE_H_
#define INMEMORYBUSEXAMPLEMODULE_H_

#include "InMemoryBus/InMemoryBusModule.h"

namespace InMemoryBusExample {

//<-
template <class T, class... TArgs>
struct ifactory {
  virtual ~ifactory() noexcept = default;
  virtual std::unique_ptr<T> create(TArgs&&...) const = 0;
};

template <class, class, class>
struct factory_impl;

template <class TInjector, class T, class I, class... TArgs>
struct factory_impl<TInjector, T, ifactory<I, TArgs...>> : ifactory<I, TArgs...> {
  explicit factory_impl(const TInjector& injector) : injector_((TInjector&)injector) {}

  std::unique_ptr<I> create(TArgs&&... args) const override {
    // clang-format off
    auto injector = di::make_injector(
      std::move(injector_)
#if (__clang_major__ == 3) && (__clang_minor__ > 4) || defined(__GCC___) || defined(__MSVC__)
    , di::bind<TArgs>().to(std::forward<TArgs>(args))[di::override]...
#else // wknd for clang 3.4
    , di::core::dependency<di::scopes::instance, TArgs, TArgs, di::no_name, di::core::override>(std::forward<TArgs>(args))...
#endif
    );
    // clang-format on

    return injector.template create<std::unique_ptr<T>>();
  }

 private:
  TInjector& injector_;
};

template <class T>
struct factory {
  template <class TInjector, class TDependency>
  auto operator()(const TInjector& injector, const TDependency&) const noexcept {
    static auto sp = std::make_shared<factory_impl<TInjector, T, typename TDependency::expected>>(injector);
    return sp;
  }
};

struct interface {
  virtual ~interface() noexcept = default;
  virtual void dummy1() = 0;
};
//->

struct implementation : interface {
  void dummy1() override {}
};

struct implementation_with_args : interface {
  implementation_with_args(int i, double d) {
    assert(42 == i);
    assert(87.0 == d);
  }
  void dummy1() override {}
};

/*<<example `example` class>>*/
class example {
 public:
  example(const ifactory<interface>& f1, const ifactory<interface, int, double>& f2) {
    assert(dynamic_cast<implementation*>(f1.create().get()));
    assert(dynamic_cast<implementation_with_args*>(f2.create(42, 87.0).get()));
  }
};


auto inmemorybusexample_module = []
{
  return (di::make_injector(
        di::bind<interface>().to<implementation>(),
        di::bind<ifactory<interface>>().to(factory<implementation>{}),
        di::bind<ifactory<interface, int, double>>().to(factory<implementation_with_args>{}),
        InMemoryBus::inmemorybus_module()));
};

}

#endif /* INMEMORYBUSEXAMPLEMODULE_H_ */
