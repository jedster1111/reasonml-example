# reasonml-example

A repo to try out building some basic examples using Reason.

## Resources

- I found this tutorial series by Lucas Reis very useful.
  - [Part 1](https://lucasmreis.github.io/blog/learning-reasonml-part-1/)
  - [Part 2](https://lucasmreis.github.io/blog/learning-reasonml-part-2/)
  - [Part 3](https://lucasmreis.github.io/blog/learning-reasonml-part-3/)
- [Common Js idioms in ReasonML](https://blog.g2i.co/common-javascript-idioms-in-reasonml-900a731b5620)
- Using [Json Placeholder](https://jsonplaceholder.typicode.com) to try out api calls.

## Tools

- [Ocaml to Reason translator Chrome extension](https://chrome.google.com/webstore/detail/reason-tools/kmdelnjbembbiodplmhgfjpecibfhadd)
  - Since Reason's online presence (particularly for help) is quite small at the moment, might have better luck looking for OCaml questions and translating any code into Reason.
- The [Reason Discord channel](https://discordapp.com/invite/reasonml) seems like a good place to get some help if you get stuck (Pretty active and people seem willing to answer questions).

## Run Project

- Install dependencies: `yarn` or `yarn install`
- Start bucklescript to compile .re to .js: `yarn bucklescript`
- Start Webpack Dev Server: `yarn start`
  - Have to refresh the page to see changes (no hot reload)

### Others

- Start webpack in watch mode to bundle .js files: `yarn webpack`


**For more elaborate ReasonReact examples**, please see <https://github.com/reasonml-community/reason-react-example>

## Build for Production

```sh
npm run build
npm run webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version.

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.

## VSCode Extension

[reason-vscode by Jared Forsyth](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode)
