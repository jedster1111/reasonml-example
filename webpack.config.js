const HtmlWebpackPlugin = require("html-webpack-plugin");

const htmlPlugin = new HtmlWebpackPlugin({
  template: "src/index.html",
  filename: "index.html"
});

module.exports = {
  entry: "./src/index.bs.js",
  mode: "development",
  plugins: [htmlPlugin],
  module: {
    rules: [
      {
        test: /\.js$/,
        exclude: /node_modules/,
        use: {
          loader: "babel-loader"
        }
      }
    ]
  },
  devServer: {
    historyApiFallback: true
  }
};
