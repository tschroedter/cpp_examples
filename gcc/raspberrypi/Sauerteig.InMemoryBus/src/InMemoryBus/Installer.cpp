/*
 * Installer.cpp
 *
 *  Created on: 9 Jan. 2018
 *      Author: tom
 */

#include "Installer.h"
#include "Hypodermic/ContainerBuilder.h"
#include "IBus.h"
#include "MessageBus.h"
#include "Common/MessagesQueue.h"
#include "Common/MessageBusSynchronization.h"

#include "Notifiers/MessageBusNotifier.h"
#include "Notifiers/IMessageBusNotifier.h"
#include "Notifiers/Factories/MessageBusNotifierFactory.h"
#include "Notifiers/Factories/IMessageBusNotifierFactory.h"
#include "Notifiers/NotifierThreadPool.h"
#include "Notifiers/INotifierThreadPool.h"
#include "Notifiers/SubscibersNotifier.h"
#include "Notifiers/ISubscibersNotifier.h"
#include "Notifiers/SubscriberFunctionCaller.h"
#include "Notifiers/ISubscriberFunctionCaller.h"
#include "Notifiers/Factories/MessageBusNotifierFactory.h"
#include "Notifiers/Factories/IMessageBusNotifierFactory.h"
#include "Notifiers/Factories/SubscibersNotifierFactory.h"
#include "Notifiers/Factories/ISubscibersNotifierFactory.h"
#include "Notifiers/Failed/FailedToNotify.h"
#include "Notifiers/Failed/IFailedToNotify.h"
#include "Notifiers/Failed/FailedToNotifyQueue.h"
#include "Notifiers/Failed/IFailedToNotifyQueue.h"
#include "Notifiers/Failed/FailedToNotifyManager.h"
#include "Notifiers/Failed/IFailedToNotifyManager.h"
#include "Notifiers/Failed/ThreadSafe/ThreadSafeFailedToNotifyQueue.h"
#include "Notifiers/Failed/ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "Notifiers/Failed/FailedMessageBusNotifier.h"
#include "Notifiers/Failed/IFailedMessageBusNotifier.h"
#include "Notifiers/Failed/FailedSubscriberFunctionCaller.h"
#include "Notifiers/Failed/IFailedSubscriberFunctionCaller.h"
#include "Notifiers/Failed/FailedMessageQueueProcessor.h"
#include "Notifiers/Failed/IFailedMessageQueueProcessor.h"

#include "Publishers/MessageBusPublisher.h"
#include "Publishers/IMessageBusPublisher.h"

#include "Subscribtions/SubscribtionManager.h"
#include "Subscribtions/ISubscribtionManager.h"
#include "Subscribtions/Subscribers/SubscriberInformationRepository.h"
#include "Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "Subscribtions/Subscribers/ISubscriberInformationRepository.h"
#include "Subscribtions/Subscribers/Factories/SubscriberInformationEntityFactory.h"
#include "Subscribtions/Subscribers/Factories/ISubscriberInformationEntityFactory.h"
#include "Subscribtions/Subscribers/UnknownSubscriberInformationEntityEntity.h"
#include "Subscribtions/Subscribers/Threadsafe/ThreadSafeSubscriberInformationRepository.h"
#include "Subscribtions/Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"
#include "Subscribtions/MessageToSubscribers/MessageToSubscribersEntityFactory.h"
#include "Subscribtions/MessageToSubscribers/IMessageToSubscribersEntityFactory.h"
#include "Subscribtions/MessageToSubscribers/IMessageToSubscribersEntity.h"

#include "Subscribtions/MessageToSubscribers/MessageToSubscribersEntity.h"
#include "Subscribtions/MessageToSubscribers/IMessageToSubscribersEntity.h"
#include "Subscribtions/MessageToSubscribers/MessageToSubscribersRepository.h"
#include "Subscribtions/MessageToSubscribers/IMessageToSubscribersRepository.h"

namespace InMemoryBus {

void Installer::register_components(Hypodermic::ContainerBuilder& builder) {
    // Common
    builder.registerType<InMemoryBus::Common::MessagesQueue>().as<InMemoryBus::Common::IMessagesQueue>().singleInstance();
    builder.registerType<InMemoryBus::Common::MessageBusSynchronization>().singleInstance();    // Todo interface IMessageBusSynchronization>()

    // Notifiers
    builder.registerType<InMemoryBus::Notifiers::Factories::MessageBusNotifierFactory>().as<InMemoryBus::Notifiers::Factories::IMessageBusNotifierFactory>();
    builder.registerType<InMemoryBus::Notifiers::Factories::SubscibersNotifierFactory>().as<InMemoryBus::Notifiers::Factories::ISubscibersNotifierFactory>();
    builder.registerType<InMemoryBus::Notifiers::MessageBusNotifier>().as<InMemoryBus::Notifiers::IMessageBusNotifier>();
    builder.registerType<InMemoryBus::Notifiers::NotifierThreadPool>().as<InMemoryBus::Notifiers::INotifierThreadPool>();
    builder.registerType<InMemoryBus::Notifiers::SubscibersNotifier>().as<InMemoryBus::Notifiers::ISubscibersNotifier>();
    builder.registerType<InMemoryBus::Notifiers::SubscibersNotifier>().as<InMemoryBus::Notifiers::ISubscibersNotifier>();
    builder.registerType<InMemoryBus::Notifiers::SubscriberFunctionCaller>().as<InMemoryBus::Notifiers::ISubscriberFunctionCaller>();
    builder.registerType<InMemoryBus::Notifiers::Failed::FailedMessageBusNotifier>().as<InMemoryBus::Notifiers::Failed::IFailedMessageBusNotifier>();
    builder.registerType<InMemoryBus::Notifiers::Failed::FailedSubscriberFunctionCaller>().as<InMemoryBus::Notifiers::Failed::IFailedSubscriberFunctionCaller>();
    builder.registerType<InMemoryBus::Notifiers::Failed::FailedSubscriberFunctionCaller>().as<InMemoryBus::Notifiers::Failed::IFailedSubscriberFunctionCaller>();
    builder.registerType<InMemoryBus::Notifiers::Failed::FailedToNotify>().as<InMemoryBus::Notifiers::Failed::IFailedToNotify>();
    builder.registerType<InMemoryBus::Notifiers::Failed::FailedToNotifyQueue>().as<InMemoryBus::Notifiers::Failed::IFailedToNotifyQueue>();
    builder.registerType<InMemoryBus::Notifiers::Failed::FailedToNotifyManager>().as<InMemoryBus::Notifiers::Failed::IFailedToNotifyManager>();
    builder.registerType<InMemoryBus::Notifiers::Failed::FailedMessageQueueProcessor>().as<InMemoryBus::Notifiers::Failed::IFailedMessageQueueProcessor>();
    builder.registerType<InMemoryBus::Notifiers::Failed::ThreadSafe::ThreadSafeFailedToNotifyQueue>().as<InMemoryBus::Notifiers::Failed::ThreadSafe::IThreadSafeFailedToNotifyQueue>();

    // Publisher
    builder.registerType<InMemoryBus::Publishers::MessageBusPublisher>().as<InMemoryBus::Publishers::IMessageBusPublisher>();

    // TODO check spelling of subscription/subscribtion and subscripers/subscriber
    // Subscriptions
    builder.registerType<InMemoryBus::Subscribtions::Subscribers::Factories::SubscriberInformationEntityFactory>().as<InMemoryBus::Subscribtions::Subscribers::Factories::ISubscriberInformationEntityFactory>();
    builder.registerType<InMemoryBus::Subscribtions::Subscribers::ThreadSafe::ThreadSafeSubscriberInformationRepository>().as<InMemoryBus::Subscribtions::Subscribers::ThreadSafe::IThreadSafeSubscriberInformationRepository>();
    builder.registerType<InMemoryBus::Subscribtions::Subscribers::SubscriberInformationRepository>().as<InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationRepository>();
    builder.registerType<InMemoryBus::Subscribtions::Subscribers::UnknownSubscriberInformationEntity>().singleInstance();
    builder.registerType<InMemoryBus::Subscribtions::SubscribtionManager>().as<InMemoryBus::Subscribtions::ISubscribtionManager>();
    builder.registerType<InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>().as<InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationEntity>();

    // MessageToSubscribers
    builder.registerType<InMemoryBus::Subscribtions::MessageToSubscribers::MessageToSubscribersEntityFactory>().as<InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersEntityFactory>();
    //builder.registerType<InMemoryBus::Subscribtions::MessageToSubscribers::MessageToSubscribersEntity>().as<InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersEntity>();
    builder.registerType<InMemoryBus::Subscribtions::MessageToSubscribers::MessageToSubscribersRepository>().as<InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersRepository>().singleInstance();

    builder.registerInstanceFactory([](::Hypodermic::ComponentContext&)
    {
        IMessageToSubscribersEntityVector_SPtr sp_vector = std::make_shared<std::vector<std::shared_ptr<InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersEntity>>>();
        return sp_vector;
    });

    // Other
    builder.registerType<MessageBus>().as<IBus>();
}

}
