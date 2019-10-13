# OOP_nanotekspice_2018
Epitech's NanoTekSpice from 2018, in C++. Made with Cynthia Bon

### Description
NanoTekSpice is a logic simulator that builds a graph (the nodes of which will be simulated digital electronic
components, inputs or outputs) from a configuration file, and injects values into that graph to get results.

### USAGE :

```
  ./nanotekspice circuit_file.nts input_name=input_value
```
Example of Circuit File :

```
# three inputs and gate
. chipsets :
input i0
input i1
input i2
4081 and0
output out
. links :
i0 :1 and0 :1
i1 :1 and0 :2
and0 :3 and0 :5
i2 :1 and0 :6
and0 :4 out :1
```
