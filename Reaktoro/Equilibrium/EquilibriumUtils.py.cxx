// Reaktoro is a unified framework for modeling chemically reactive systems.
//
// Copyright © 2014-2024 Allan Leal
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this library. If not, see <http://www.gnu.org/licenses/>.

// pybind11 includes
#include <Reaktoro/pybind11.hxx>

// Reaktoro includes
#include <Reaktoro/Core/ChemicalState.hpp>
#include <Reaktoro/Equilibrium/EquilibriumOptions.hpp>
#include <Reaktoro/Equilibrium/EquilibriumRestrictions.hpp>
#include <Reaktoro/Equilibrium/EquilibriumResult.hpp>
#include <Reaktoro/Equilibrium/EquilibriumSolver.hpp>
#include <Reaktoro/Equilibrium/EquilibriumUtils.hpp>
using namespace Reaktoro;

void exportEquilibriumUtils(py::module& m)
{
    m.def("equilibrate", py::overload_cast<ChemicalState&>(equilibrate));
    m.def("equilibrate", py::overload_cast<ChemicalState&, const EquilibriumOptions&>(equilibrate));
    m.def("equilibrate", py::overload_cast<ChemicalState&, const EquilibriumRestrictions&>(equilibrate));
    m.def("equilibrate", py::overload_cast<ChemicalState&, const EquilibriumRestrictions&, const EquilibriumOptions&>(equilibrate));

    m.def("equilibrate", py::overload_cast<ChemicalState&, ArrayXdConstRef>(equilibrate));
    m.def("equilibrate", py::overload_cast<ChemicalState&, const EquilibriumOptions&, ArrayXdConstRef>(equilibrate));
    m.def("equilibrate", py::overload_cast<ChemicalState&, const EquilibriumRestrictions&, ArrayXdConstRef>(equilibrate));
    m.def("equilibrate", py::overload_cast<ChemicalState&, const EquilibriumRestrictions&, const EquilibriumOptions&, ArrayXdConstRef>(equilibrate));
}
