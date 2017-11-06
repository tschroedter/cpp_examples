/*
 * IADCTemperatures.h
 *
 *  Created on: 4 Nov. 2017
 *      Author: tom
 */

#ifndef INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADCTEMPERATURES_H_
#define INTERFACES_IO_ANALOGEDIGITALCONVERTERS_IADCTEMPERATURES_H_

#include <memory>
#include "../../../CommonTypes.h"
#include "IADC.h"
#include "IADC0832.h"
#include "ThreadSafe/IThreadSafeADC0832.h"

class IADCTemperatures : public IADC {
 public:
    virtual ~IADCTemperatures() = default;
};

typedef std::shared_ptr<IADCTemperatures> IADCTemperatures_SPtr;

#endif /* INTERFACES_IO_IADCTEMPERATURES_H_ */
