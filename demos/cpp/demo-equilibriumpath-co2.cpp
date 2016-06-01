// Reaktoro is a unified framework for modeling chemically reactive systems.
//
// Copyright (C) 2014-2015 Allan Leal
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include <Reaktoro/Reaktoro.hpp>
using namespace Reaktoro;

int main()
{
    ChemicalEditor editor;
    editor.addAqueousPhase("H O C Na Cl");

    ChemicalSystem system(editor);

    EquilibriumProblem problem1(system);
    problem1.add("H2O", 1, "kg");
    problem1.add("CO2", 0.5, "mol");
    problem1.add("HCl", 1, "mol");

    EquilibriumProblem problem2(system);
    problem2.add("H2O", 1, "kg");
    problem2.add("CO2", 0.5, "mol");
    problem2.add("NaOH", 2, "mol");

    ChemicalState state1 = equilibrate(problem1);
    ChemicalState state2 = equilibrate(problem2);

    EquilibriumPath path(system);

    ChemicalPlot plot = path.plot();
    plot.setXData("pH");
    plot.addYData("speciesMolality(HCO3-)", "HCO@_3^-");
    plot.addYData("speciesMolality(CO2(aq))", "CO_2(aq)");
    plot.addYData("speciesMolality(CO3--)", "CO@_3^{2-}");
    plot.setXLabel("pH");
    plot.setYLabel("Concentration [molal]");
    plot.setYFormat("%g");
    plot.setKey("left center Left reverse");

    ChemicalOutput output = path.output();
    output.addData("t");
    output.addData("pH");
    output.addData("speciesMolality(HCO3-)");
    output.addData("speciesMolality(CO2(aq))");
    output.addData("speciesMolality(CO3--)");
    output.setOutputFile("result.txt");

    path.solve(state1, state2);
}
