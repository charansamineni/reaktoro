// Reaktor is a C++ library for computational reaction modelling.
//
// Copyright (C) 2014 Allan Leal
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

#pragma once

// C++ includes
#include <memory>

namespace Reaktor {

// Forward declarations
class ChemicalSystem;
class EquilibriumOptions;
class EquilibriumProblem;
class EquilibriumResult;
class Partition;

/// A type used to solve equilibrium problems
class EquilibriumSolver
{
public:
    /// Construct a default EquilibriumSolver instance
    EquilibriumSolver();

    /// Construct a EquilibriumSolver instance
    explicit EquilibriumSolver(const ChemicalSystem& system);

    /// Construct a EquilibriumSolver instance with partition information
    EquilibriumSolver(const ChemicalSystem& system, const Partition& partition);

    /// Solve a equilibrium problem with default options
    /// @param problem The definition of the equilibrium problem
    /// @param result[in,out] The initial guess and the final result of the equilibrium problem
    auto solve(const EquilibriumProblem& problem, EquilibriumResult& result) -> void;

    /// Solve a equilibrium problem with specified options
    /// @param problem The definition of the equilibrium problem
    /// @param result[in,out] The initial guess and the final result of the equilibrium problem
    /// @param options The options for the equilibrium calculation
    auto solve(const EquilibriumProblem& problem, EquilibriumResult& result, const EquilibriumOptions& options) -> void;

private:
    struct Impl;

    std::shared_ptr<Impl> pimpl;
};

} // namespace Reaktor
