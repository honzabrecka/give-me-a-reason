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
