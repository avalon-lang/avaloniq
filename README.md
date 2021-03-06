# Avalon - A classical-quantum programming language

Quantum computing is progressing slowly but surely. And as it progresses, tools are going to be needed to program quantum computers.

Avalon is a programming language aimed at a specific class of quantum computers called classical-quantum hybrid quantum computers.
A hybrid classical-quantum computer has the property of having a classical computer driving (telling) the quantum computer what to do.
These computers are being built by IBM and Rigetti and Avalon seeks to target both, starting with Rigetti.

Currently, all you will get is an interpreter to start prototyping on your own system while I'm working on generating QUIL (Rigetti) code.
The documentation can be found at [Read The Docs](https://avalon-lang.readthedocs.io/en/latest) and please do look in the `tests/integration` folder for sample code to run.

## Why Avalon

Quantum computing is progressing and it needs tools among which programming languages are going to play 
a vital role. Yes, there exists other programming languages that target hybrid classical-quantum computers 
but I have found them to be lacking in abstractions and many even exposing hardware primitives 
making them unfriendly to the novice developer.

Even more important, as we approach the NISQ era, compilers are going to play a vital role 
in the optimisation of quantum programs when we have little to no error correction 
built into the hardware. It is the hope that Avalon will come out as the leading 
programming language for writing programs meant for near-term quantum computers.

## What it looks like

![Avalon sample program in my editor](images/entanglement.avl.png "Avalon program in Sublime Text")

## State of the project

Currently, the classical part is close to 90% finished (excluding known bugs). The missing feature is pointer types.
Getters and setters are being reworked into a better form. Otherwise the rest works as intended.

The quantum part, 1-Qubit data types and gates that act on them are implemented and can be tested.
The 2-Qubits, 4-Qubits and 8-Qubits data types are implemented but gates that operate on them are still missing but upcoming.

## Show me the code

Please find below the teleportation code found in ``tests/integration/quantum/teleportation.avl`` reproduced for your copy-paste-run pleasure.

```
import io
import quant

def __main__ = (val args : [string]) -> void:
    -- initialize quantum variables
    val source = 0q1,
        destination = 0q0,
        ancilla = 0q0

    -- create an entanglement between the destination and the ancilla
    Quant.had(ref destination)
    Quant.cx(ref destination, ref ancilla)

    -- perform the teleportation
    Quant.cx(ref source, ref ancilla)
    Quant.had(ref source)

    -- measure the source and the ancilla
    var source_bit = cast(ref source) -> bit,
        ancilla_bit = cast(ref ancilla) -> bit

    -- perform phase correction on the destination
    if source_bit == 0b1:
        Quant.pz(ref destination)
    if ancilla_bit == 0b1:
        Quant.px(ref destination)

    -- measure and print the destination which should contain <0q1>
    var destination_bit = cast(ref destination) -> bit
    Io.println(string(destination_bit))

    return
```

## Installation

Currently, installation can only happen from source and the code has only been tested on a Linux system.  
Installation directions can be found at [installing Avalon](https://avalon-lang.readthedocs.io/en/latest/installation.html).

## Documentation

Documentation is currently being written as the language evolves.  
You can find the documentation at [Read The Docs](https://avalon-lang.readthedocs.io/en/latest).

## Contributing

Thank you for considering it. Please see the [contribution guidelines](https://github.com/avalon-lang/avaloniq/blob/master/CONTRIBUTING.md) for help on contributing.

## Contact

You can reach me at <a href="mailto:nbashige@gmail.com">nbashige@gmail.com</a>

## License

This code is licensed under the MIT license. Please see the LICENSE file for the terms.

## Acknowledgement

Development of Avalon is being supported by the [Unitary Fund](https://unitary.fund) grant.
My thanks to [Will J. Zeng](willzeng.com) for running the program.

## Copyright

Copyright (c) 2018 Ntwali Bashige Toussaint

In case you found code that is yours and I failed to give attribution or I am claiming copyright of the code, please do email me to resolve the issue.

