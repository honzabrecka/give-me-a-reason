// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Random = require("bs-platform/lib/js/random.js");

function unwrap(a, b) {
  if (a.tag) {
    if (b.tag) {
      return a[0] + b[0];
    } else {
      return "foo";
    }
  } else if (a[0] === "foo" && !b.tag) {
    return b[0];
  } else {
    return "foo";
  }
}

console.log(unwrap(/* Left */Block.__(0, ["foo"]), /* Left */Block.__(0, ["x"])));

function foo(x) {
  console.log(x);
  return x;
}

console.log(Random.$$int(10));

function inc(param) {
  return 1 + param | 0;
}

var r = List.fold_left((function (prim, prim$1) {
        return prim + prim$1 | 0;
      }), 0, List.map(inc, /* :: */[
          1,
          /* :: */[
            2,
            /* :: */[
              3,
              /* [] */0
            ]
          ]
        ]));

console.log(r);

function now() {
  return /* Millis */[12];
}

function tap(f, v) {
  Curry._1(f, v);
  return v;
}

function $(f, g, x) {
  return Curry._1(f, Curry._1(g, x));
}

function flip(f, a, b) {
  return Curry._2(f, b, a);
}

function bind(prim, prim$1) {
  return prim$1.then(Curry.__1(prim));
}

function pure(prim) {
  return Promise.resolve(prim);
}

function $great$great$eq(param, param$1) {
  return param.then(Curry.__1(param$1));
}

var Promise$1 = /* module */[
  /* bind */bind,
  /* pure */pure,
  /* >>= */$great$great$eq
];

var p = new Promise((function (resolve, _) {
        return resolve(2);
      }));

function prim(param) {
  return Promise.resolve((console.log(param), param));
}

p.then(prim);

$great$great$eq($great$great$eq(p, (function (param) {
            return Promise.resolve((console.log(param), param));
          })), pure);

var x = "foo";

exports.x = x;
exports.unwrap = unwrap;
exports.foo = foo;
exports.inc = inc;
exports.r = r;
exports.now = now;
exports.tap = tap;
exports.$ = $;
exports.flip = flip;
exports.Promise = Promise$1;
exports.p = p;
/*  Not a pure module */
