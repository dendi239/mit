===
MIT
===

This is home repo for all stuff I'm doing with MIT lectures on OpenCousreWare.
It's build with bazel, so it's likely to have some issues with editing in editors.

Build system
------------

Bazel_ is chosen as build system for this project.
It's expected to build all code there as well as pdf files or whatever else one might need.

.. _bazel: https://bazel.build

Third party
+++++++++++

This repository stores all third party libraries as git-submodules.
That's why you need to run following to get them.

.. code-block:: bash

  git submodule update --init --recursive

``compile_commands.json``
-------------------------

``compile_commands.json`` is common way wo provide information about where to find sources, usually to clangd.
Hopefully, you don't need to generate your own, just reuse existing one.
To generate new, just run:

.. code-block:: bash
  
  bazel run @hedron_compile_commands//:refresh_all

