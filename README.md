esy-bsb-example
---

This is a an example project for [bsb-native](https://github.com/bsansouci/bsb-native) working inside [esy](https://esy.sh) using the opam package called [Alcotest](https://github.com/mirage/alcotest).

You'll need to install esy for this: `npm install -g esy`

## Install
`esy install`

## Build
`esy build`

## Run
`esy x example.byte`


## Some Details

### bsb-native part
The build system used here is called [bsb-native](https://github.com/bsansouci/bsb-native). It uses a single config file called `bsconfig.json` which describes everything it needs to know. See the README of bsb-native for explanation of how it works.

The branch `#esy-support` allows for a new flag called `-build-library` (see [usage here](https://github.com/bsansouci/esy-bsb-example-library)) which is used to create a library file. You need to remember to add that command for your package to be usable from the outside, otherwise you're building your package's `"entries"` in your `bsconfig.json`.

### esy part
Esy is a package manager, you can read about it [here](https://esy.sh).

It allows for a custom config object called `"esy"` in the `package.json` (or in a special file called `esy.json`). The `"build"` field contains the commands executed when `esy build` is called.

### package.json -> opam part
Esy uses the [ocamlfind](http://projects.camlcity.org/projects/dl/findlib-1.7.3/doc/ref-html/index.html) meta files to understand how to coordinate the builds and cache of the project and its dependencies.

Bsb-native (on the `#esy-support` branch) supports generating everything you need for Esy to understand your package AND to publish on the [opam package manager](https://opam.ocaml.org) (notably it generates the `opam`, `META` and `<packagename>.install` files). This works by reading your `package.json` for information. It uses great defaults for building libraries and enables a custom config object inside package.json called `"opam"`, which you can see in this project. See more details on what info comes from where [here](https://github.com/bsansouci/opam_of_packagejson).
