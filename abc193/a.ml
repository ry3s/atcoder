let _ =
  let a, b = Scanf.scanf "%d %d" (fun x y -> (x, y)) in
  let a, b = (float_of_int a, float_of_int b) in
  let ans = 1.0 -. (b /. a) in
  Printf.printf "%f\n" (ans *. 100.)
