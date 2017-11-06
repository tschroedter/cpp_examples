/*
 * IThreadSafeADC0832.h
 *
 *  Created on: 4 Nov. 2017
 *      Author: tom
 */

#ifndef INTERFACES_IO_ANALOGEDIGITALCONVERTERS_THREADSAFE_ITHREADSAFEADC0832_H_
#define INTERFACES_IO_ANALOGEDIGITALCONVERTERS_THREADSAFE_ITHREADSAFEADC0832_H_

#include <memory>
#include "../IADC0832.h"
#include "../../../../CommonTypes.h"

class IThreadSafeADC0832 : public IADC0832 {
 public:
    virtual ~IThreadSafeADC0832() = default;

    virtual void set_adc0832(IADC0832_SPtr adc0832) = 0;
};

typedef std::shared_ptr<IThreadSafeADC0832> IThreadSafeADC0832_SPtr;

#endif /* INTERFACES_IO_ITHREADSAFEADC0832_H_ */
