﻿/*
 * PathFinder.cs
 * Class for translating hash and friendly name to name of the file.
 *
   Copyright 2017 Roman Lisak

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
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Spectre.Database.Entities;

namespace Spectre.Database.Utils
{
    /// <summary>
    /// Class for finding the path of chosen property.
    /// </summary>
    public class PathFinder
    {
        /// <summary>
        /// The temporary...
        /// </summary>
        private static string _hash;

        /// <summary>
        /// The friendlyname...
        /// </summary>
        private static string _friendlyname;

        /// <summary>
        /// Returns for hash.
        /// </summary>
        /// <param name="hash">The hash.</param>
        /// <returns>
        /// Returns location having hash.
        /// </returns>
        public string ReturnForHash(string hash)
        {
            using (var context = new Context())
            {
                var location = context.Datasets
                    .Where(b => b.Hash == hash)
                    .FirstOrDefault();
                _hash = location.ToString();
            }

            return _hash;
        }

        /// <summary>
        /// Returns the name of friendly name.
        /// </summary>
        /// <param name="hash">The hash.</param>
        /// <returns>
        /// Returns location having friendly name.
        /// </returns>
        public string ReturnForFriendlyName(string hash)
        {
            using (var context = new Context())
            {
                var location = context.Datasets
                    .Where(b => b.Hash == hash)
                    .FirstOrDefault();
                _friendlyname = location.ToString();
            }

            return _friendlyname;
        }
    }
}
