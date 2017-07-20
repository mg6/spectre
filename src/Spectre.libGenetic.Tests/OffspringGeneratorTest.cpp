/*
* OffspringGeneratorTest.cpp
* Tests offspring generator.
*
Copyright 2017 Grzegorz Mrukwa

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

#define GTEST_LANG_CXX11 1

#include <gtest/gtest.h>
#include "Spectre.libGenetic/IndividualsBuilderStrategy.h"
#include "Spectre.libGenetic/PreservationStrategy.h"

namespace
{
using namespace Spectre::libGenetic;

class MockIndividualsBuilderStrategy : public IndividualsBuilderStrategy {
public:
	Generation Build()
	{
		const Individual true_individual = Individual({ true, true, true, true });
		return Generation({ true_individual, true_individual, true_individual });
	}
};

class MockPreservationStrategy : public PreservationStrategy {
public:
	Generation PickBest()
	{
		const Individual true_individual = Individual({ true, true, true, true });
		return Generation({ true_individual, true_individual, true_individual });
	}
};

class OffspringGeneratorTest : public ::testing::Test
{
public:
	OffspringGeneratorTest(MockIndividualsBuilderStrategy&& builder, MockPreservationStrategy&& preservationStrategy) {}
protected:

	void SetUp() override
	{
		MockIndividualsBuilderStrategy builder = new MockIndividualsBuilderStrategy();
		MockPreservationStrategy preservationStrategy = new MockPreservationStrategy();
	}
};

}
