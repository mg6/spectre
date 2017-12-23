/*
* Types.h
* Types used in classifiers.
*
Copyright 2017 Spectre Team

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once
#include <opencv2/core/mat.hpp>
#include <span.h>
#include "Empty.h"

namespace Spectre::libClassifier
{
    using DataType = float;
    using Observation = gsl::span<const DataType>;
    using Label = signed;
    const auto CV_TYPE = CV_32FC1;
    const auto CV_LABEL_TYPE = CV_32SC1;
    using Seed = _ULonglong; // @gmrukwa: from mt19937_64

    enum SVM_TYPE
    {
        C_SVC = 0,
        NU_SVC = 1,
        ONE_CLASS = 2,
        EPS_SVR = 3,
        NU_SVR = 4
    };

    inline const char* ToString(SVM_TYPE v)
    {
        switch (v)
        {
        case C_SVC:   return "C_SVC";
        case NU_SVC:   return "NU_SVC";
        case ONE_CLASS: return "ONE_CLASS";
        case EPS_SVR: return "EPS_SVR";
        case NU_SVR: return "NU_SVR";
        default:      return "[Unknown OS_type]";
        }
    }
}
