let x, y = Scanf.scanf " %d %d" (fun x y -> (x, y))
let () = Printf.printf "%d\n" (if x < y then y else x)
