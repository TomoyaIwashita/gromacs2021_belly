/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright (c) 2020, by the GROMACS development team, led by
 * Mark Abraham, David van der Spoel, Berk Hess, and Erik Lindahl,
 * and including many others, as listed in the AUTHORS file in the
 * top-level source directory and at http://www.gromacs.org.
 *
 * GROMACS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * GROMACS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GROMACS; if not, see
 * http://www.gnu.org/licenses, or write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
 *
 * If you want to redistribute modifications to GROMACS, please
 * consider that scientific software is very special. Version
 * control is crucial - bugs must be traceable. We will be happy to
 * consider code for inclusion in the official distribution, but
 * derived work must not be called official GROMACS. Details are found
 * in the README & COPYING files - if they are missing, get the
 * official version at http://www.gromacs.org.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the research papers on the package. Check out http://www.gromacs.org.
 */
/*! \internal \file
 * \brief
 * Header for runner for CUDA float3 type layout tests.
 *
 * \author Artem Zhmurov <zhmurov@gmail.com>
 */
#ifndef GMX_GPU_UTILS_TESTS_TYPECASTS_RUNNER_H
#define GMX_GPU_UTILS_TESTS_TYPECASTS_RUNNER_H

#include "gmxpre.h"

#include <vector>

#include <gtest/gtest.h>

#include "gromacs/math/vectypes.h"

#include "testutils/test_device.h"

namespace gmx
{

namespace test
{

/*! \brief Tests the compatibility of RVec and float3 using the conversion on host.
 *
 * \param[out] rVecOutput  Data in RVec format for the output.
 * \param[in]  rVecInput   Data in RVec format with the input.
 */
void convertRVecToFloat3OnHost(std::vector<gmx::RVec>& rVecOutput, const std::vector<gmx::RVec>& rVecInput);

/*! \brief Tests the compatibility of RVec and float3 using the conversion on device.
 *
 * \param[out] rVecOutput  Data in RVec format for the output.
 * \param[in]  rVecInput   Data in RVec format with the input.
 * \param[in]  testDevice  Test herdware environment to get DeviceContext and DeviceStream from.
 */
void convertRVecToFloat3OnDevice(std::vector<gmx::RVec>&       rVecOutput,
                                 const std::vector<gmx::RVec>& rVecInput,
                                 const TestDevice*             testDevice);


} // namespace test
} // namespace gmx

#endif // GMX_GPU_UTILS_TESTS_TYPECASTS_RUNNER_H
