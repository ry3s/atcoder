let xa, ya, xb, yb, xc, yc =
  Scanf.scanf " %f %f %f %f %f %f" (fun xa ya xb yb xc yc -> (xa, ya, xb, yb, xc, yc))
let ans = (abs_float @@ (ya *. (xb -. xc) +. yb *. (xc -. xa) +. yc *. (xa -. xb))) /. 2.
let () = Printf.printf "%f\n" ans
