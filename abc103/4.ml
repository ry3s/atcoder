let () =
  let n, m = Scanf.scanf "%d %d\n" (fun x y -> x, y) in
  Array.init m (fun _ -> Scanf.scanf " %d %d"
                           (fun x y -> (x, y))) in
    
