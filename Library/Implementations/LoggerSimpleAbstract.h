#ifndef LOGGINGSYSTEM_LOGGERSIMPLEABSTRACT_H
#define LOGGINGSYSTEM_LOGGERSIMPLEABSTRACT_H

#include <list>
#include <string>
#include <map>

#include "Logger.h"

class LoggerSimpleAbstract {

public:

    virtual void setUsingDynamicTabs(bool value) = 0;

    virtual void setTabWidthApplicationId(int value) = 0;

    virtual void setTabWidthApplicationVersion(int value) = 0;

    virtual void setTabWidthTime(int value) = 0;

    virtual void setTabWidthTag(int value) = 0;

    virtual void setShowTimeInNanos(bool value) = 0;

    virtual void resetTabWidths() = 0;

    virtual void resetDynamicTabs() = 0;
};


#endif //LOGGINGSYSTEM_LOGGERSIMPLEABSTRACT_H
