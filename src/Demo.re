let x: string = "foo";

type either('a, 'b) = Left('a) | Right('b);

type x = either(string, string)

let unwrap = (a: x, b: x) =>
  switch (a, b) {
  | (Left("foo"), Left(b)) => b
  | (Right(c), Right(d)) => c ++ d
  | _ => "foo"
  };

Js.log(unwrap(Left("foo"), Left("x")))

/* let map = (f, v) => */

let foo = (x: 'a): 'a => {
  let y = x;
  Js.log(x);
  y;
};

Js.log(Random.int(10));

let inc = (+)(1);

let r = [1, 2, 3]
  |> List.map(inc)
  |> List.fold_left((+), 0);

Js.log(r)

type millis = Millis(int);

let now = (): millis => Millis(12)

let tap = (f: ('a => unit), v: 'a): 'a => {
  f(v);
  v;
};

let ($) = (f, g, x) => f(g(x));

let flip = (f, a, b) => f(b, a)

module Promise {
  let bind = Js.Promise.then_;
  let pure = Js.Promise.resolve;
  let (>>=) = flip(Js.Promise.then_)
};

open Promise;

let p = Js.Promise.make((~resolve, ~reject) => resolve(. 2));

p |> bind (pure $ tap(Js.log));

p >>= (pure $ tap(Js.log)) >>= pure;
