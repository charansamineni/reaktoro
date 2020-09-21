// Reaktoro is a unified framework for modeling chemically reactive systems.
//
// Copyright (C) 2014-2020 Allan Leal
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
#include <pybind11/pybind11.h>
namespace py = pybind11;

// Reaktoro includes
#include <Reaktoro/Core/Phases.hpp>
using namespace Reaktoro;

void exportPhases(py::module& m)
{
    py::class_<Speciate>(m, "Speciate")
        .def(py::init<>())
        .def_readwrite("symbols", &Speciate::symbols)
        ;

    m.def("speciate", speciate);

    py::class_<Phases>(m, "Phases")
        .def(py::init<const Database&>())
        .def("add", py::overload_cast<const GenericPhase&>(&Phases::add))
        .def("add", py::overload_cast<const GenericPhasesGenerator&>(&Phases::add))
        .def("database", &Phases::database)
        ;
}
