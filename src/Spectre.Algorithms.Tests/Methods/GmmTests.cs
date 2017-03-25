﻿/*
 * GmmTests.cs
 * Checks, whether MCR is properly called and result may be obtained.
 * 
   Copyright 2017 Wilgierz Wojciech, Grzegorz Mrukwa

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
using System;
using NUnit.Framework;
using Spectre.Algorithms.Methods;
using Spectre.Data.Datasets;

namespace Spectre.Algorithms.Tests.Methods
{
	[TestFixture, Category("Algorithm")]
	public class GmmTests
	{
		Gmm _gmm;

		[OneTimeSetUp]
		public void SetUpClass()
		{
			_gmm = new Gmm();
		}

		[OneTimeTearDown]
		public void TearDownClass()
		{
			_gmm.Dispose();
		}

		[Test]
		public void EstimateGmm()
		{
			double[] mz = { 1, 2, 3 };
			double[,] data = { { 1, 1.1, 1.2 }, { 1, 1.1, 1.2 }, { 1, 1.1, 1.2 } };
            IDataset dataset = new BasicTextDataset(mz, data);

			object result = _gmm.EstimateGmm(dataset, false, false);

			Console.WriteLine(result);

			// Assert
			Assert.IsNotNull(result);
		}

		[Test]
		public void ApplyGmm()
		{
			double[,] data = { { 1, 1.1, 1.2 }, { 1, 1.1, 1.2 }, { 1, 1.1, 1.2 } };
			double[] mz = { 1, 2, 3 };
            IDataset dataset = new BasicTextDataset(mz, data);

            var model = _gmm.EstimateGmm(dataset, false, false);

			IDataset result = _gmm.ApplyGmm(model, dataset);

			Console.WriteLine(result);

			// Assert
			Assert.IsNotNull(result);
		}
	}
}