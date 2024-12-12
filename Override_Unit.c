/*
 * File:   Override_Unit.c
 * Author: Kostas
 *
 * Created on 7 Δεκεμβρίου 2024, 11:35 μμ
 */


#include <xc.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Override_Unit.h"

static void* SelectDataType(Override_Unit_t* config);


void* OvU_OverrideVal(void* anyArg, Override_Unit_t* config)
{
    void* RetVal = 0;
    
    if(config == NULL)
    {
        RetVal = anyArg;
    }
    else if(config->enable)
    {
        RetVal = SelectDataType(config);
    }
    else
    {
        RetVal = anyArg;
    } 
    return RetVal;
}

static void* SelectDataType(Override_Unit_t* config)
{
    static uint8_t uint8Value;
    static uint16_t uint16Value;
    static int16_t sint16Value;
    static uint32_t uint32Value;
    static int32_t int32Value;
    static bool boolValue;
    
        switch(config->dataSize)
        {
            case DATATYPE_BOOL:
                boolValue = (bool)OverrideVal;
                return boolValue;
            break;
            case DATATYPE_UINT8:
                uint8Value = (uint8_t)OverrideVal;
                return uint8Value;
            break;
            case DATATYPE_UINT16:
                uint16Value = (uint16_t)OverrideVal;
                return uint16Value;
            break;
            case DATATYPE_SINT16:
                sint16Value = (int16_t)OverrideVal;
                return sint16Value;
            break;
            case DATATYPE_UINT32:
                uint32Value = (uint32_t)OverrideVal;
                return uint32Value;
            break;
            case DATATYPE_INT32:
                int32Value = (int32_t)OverrideVal;
                return int32Value;
            break;
        }
}