# Thoughts

## Pros

- 100% type safety
  - Very good type inference
  - Eliminates type errors
  - Have to test logic errors instead
  - Once it compiles, tends to work
  - Reduces costs of refactoring
- Variants and pattern matching are pretty cool

  ```ocaml
  type posts =
    | LoadingPosts
    | PostsLoaded(list(post))
    | Error(string)
    | NoPosts

  ...

  let render = self =>
    ...
    {
      switch (self.state.posts) {
        | LoadingPosts => renderLoadingPosts()
        | PostsLoaded(posts) => renderPosts(posts)
        | Error(errMessage) => renderError(errMessage)
        | NoPosts => renderNoPosts()
      }
    }
    ...
  ```

  - Pattern matching ensures you cover all possibilities.

- Can implement gradually into a project
  - Possibly could start out using for more complicated components/functions
  - Can use existing JavaScript code/libraries
    - Not too many existing libraries have bindings already, so might need to spend time writing your own
- Lots of stuff built in
  - Immutability
  - Reducers
  - Routing
- Functional programming benefits
  - Still possible to be imperative though
  - Opt in mutations and side-effects

## Cons

- Documentation isn't the clearest
- Much smaller and younger community than Js
- Tooling isn't as well developed at the moment
  - Particularly editor support (I've only used VSCode personally)
    - Not sure about IntelliJ IDEA specifically
- No clear consensus on how to handle global state
  - _Seen claims that the strong type safety negates the problems with prop drilling_
