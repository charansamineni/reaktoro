# Reaktoro is a unified framework for modeling chemically reactive systems.
#
# Copyright (C) 2014-2015 Allan Leal
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

from reaktoro import *

# **Note:**
# This demo should be executed on the same directory where the script is located.
# Example:
# ~~~
# cd Reaktoro/demos/python
# python demo-equilibrium-gems.py
# ~~~

# Use an exported project file from GEMS to initialize a Gems object,
gems = Gems("../resources/gems/CalciteBC-dat.lst")

# and then use it to construct the ChemicalSystem object.
system = ChemicalSystem(gems)

# Create a ChemicalState object that contains the temperature, pressure,
# and amounts of species stored in the exported GEMS file.
state = ChemicalStategems.state(system)

# Output the equilibrium state calculated by GEMS to a file.
state.output("state-gems2.txt")

# Perturb the equilibrium state calculated by GEMS
state.setSpeciesAmount("CO2@", 0.1)

# and then equilibrate the modified chemical state using Reaktoro's methods.
equilibrate(state)

# Output the updated equilibrium state to a file.
state.output("state-gems-updated2.txt")
