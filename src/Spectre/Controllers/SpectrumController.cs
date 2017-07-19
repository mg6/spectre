/*
 * SpectrumController.cs
 * Class serving GET requests for spectrum.
 * 
   Copyright 2017 Grzegorz Mrukwa, Micha� Gallus, Daniel Babiak
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

using Spectre.Data.Datasets;
using Spectre.Models.Msi;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using System.Web.Http.Cors;

namespace Spectre.Controllers
{
    [EnableCors(origins: "*", headers: "*", methods: "*")]
    public class SpectrumController : ApiController
    {
        /// <summary>
        /// Gets single spectrum of a specified preparation.
        /// </summary>
        /// <param name="id">Preparation identifier.</param>
        /// <param name="spectrumId">Spectrum identifier.</param>
        /// <returns>Spectrum</returns>
        public Spectrum Get(int id, int spectrumId)
        {
            if (id != 1)
                return null;

            var dataset = new BasicTextDataset("C:\\spectre_data\\hnc1_tumor.txt");

            var mz = dataset.GetRawMzArray();

            var intensities = dataset.GetRawIntensityArray(spectrumId);
            var coordinates = dataset.GetSpatialCoordinates(spectrumId);

            return new Spectrum() { Id = spectrumId, Intensities = intensities, Mz = mz, X = coordinates.X, Y = coordinates.Y };
        }
    }
}