let () =
  let a, b, c, x, y = Scanf.scanf "%d %d %d %d %d" (fun a b c x y -> a, b, c, x, y) in
  Array.init 100001 (fun x -> x)
  |> Array.map (fun i -> a *  (max 0 (x-i)) +  b * (max 0 (y-i))  + 2 * c * i)
  |> Array.fold_left min max_int
  |> Printf.printf "%d\n"
         
