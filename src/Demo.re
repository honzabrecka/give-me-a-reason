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

let inc = (n) => n + 1;

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

module Promise {
  let (>>=) = Js.Promise.then_;
  let pure = Js.Promise.resolve;
};

open Promise;

Js.Promise.make((~resolve, ~reject) => resolve(. 2))
|> (>>=)(pure $ tap(Js.log));
