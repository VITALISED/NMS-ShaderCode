# NMS-ShaderCode

Shader code taken from the initial macOS release of No Man's Sky

This fork has stripped .BIN files which do not seem to be used for any builds. Also fixes some file associations.


`//TF_BEGIN` and `//TF_END` refer to [The Forge](theforge.dev) and sections enclosed by these commits should be assumed to deal with macOS and iOS (and thus, Metal).

## How to build

See this gist <https://gist.github.com/VITALISED/2f0ab1ccc67ddffcc7da570d41d159c4>

## What are the root .BIN files about?

Not quite sure exactly, but they do contain the build targets for the shaders which you'll need to compile for the game.