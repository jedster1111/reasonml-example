# reasonml-example

## Resources

I found this tutorial series by Lucas Reis very useful.

- [Part 1](https://lucasmreis.github.io/blog/learning-reasonml-part-1/)
- [Part 2](https://lucasmreis.github.io/blog/learning-reasonml-part-2/)
- [Part 3](https://lucasmreis.github.io/blog/learning-reasonml-part-3/)

## Run Project

- Install dependencies: `yarn` / `yarn install`
- Start bucklescript to compile .re to .js: `yarn bucklescript`
- Start Dev Server: `yarn start`

### Others

- Start webpack in watch mode to bundle .js files: `yarn webpack`

Have to refresh the page to see changes (no hot reload)

**For more elaborate ReasonReact examples**, please see https://github.com/reasonml-community/reason-react-example

## Build for Production

```sh
npm run build
npm run webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version.

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.

## VSCode Extension

[reason-vscode by Jared Forsyth](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode)
