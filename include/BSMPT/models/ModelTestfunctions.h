// SPDX-FileCopyrightText: 2021 Philipp Basler, Margarete Mühlleitner and Jonas
// Müller
//
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once
#include <string>
#include <vector>

namespace BSMPT
{
class Class_Potential_Origin;
namespace ModelTests
{

enum class TestResults
{
  Pass,
  Fail
};

std::string TestResultsToString(const TestResults &input);

TestResults CheckNumberOfCTParameters(const Class_Potential_Origin &point);
TestResults CheckNumberOfVEVLabels(const Class_Potential_Origin &point);
TestResults CheckLegendTemp(const Class_Potential_Origin &point);
TestResults CheckNumberOfTripleCouplings(const Class_Potential_Origin &point);
TestResults CheckGaugeBosonMasses(const Class_Potential_Origin &point);
std::pair<TestResults, TestResults>
CheckFermionicMasses(const Class_Potential_Origin &point);
TestResults CheckTreeLevelMin(const Class_Potential_Origin &point,
                              int WhichMinimizer);

TestResults CheckTadpoleRelations(const Class_Potential_Origin &point);
TestResults CheckNLOMasses(const Class_Potential_Origin &point);
TestResults CheckVTreeSimplified(const Class_Potential_Origin &point);
TestResults CheckVCounterSimplified(const Class_Potential_Origin &point);
TestResults
CheckCTConditionsFirstDerivative(const Class_Potential_Origin &point);
TestResults
CheckCTConditionsSecondDerivative(const Class_Potential_Origin &point);
TestResults CheckCTIdentities(const Class_Potential_Origin &point);
TestResults CheckCTNumber(const Class_Potential_Origin &point);

TestResults CheckCKMUnitarity();
TestResults CheckSymmetricTensorScalarSecond(
    const std::vector<std::vector<double>> &Tensor);
TestResults CheckSymmetricTensorScalarThird(
    const std::vector<std::vector<std::vector<double>>> &Tensor);
TestResults CheckSymmetricTensorScalarFourth(
    const std::vector<std::vector<std::vector<std::vector<double>>>> &Tensor);
TestResults CheckSymmetricTensorLeptons();
TestResults CheckSymmetricTensorQuarks();
TestResults CheckSymmetricTensorGauge();

} // namespace ModelTests
} // namespace BSMPT
