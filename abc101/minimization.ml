let () =
  let n, k = Scanf.scanf "%d %d" (fun n k -> n, k) in
  let a =
    Array.init n (fun _ ->
        Scanf.scanf " %d" (fun x -> x)) in
  Printf.printf "%d\n" (1 + int_of_float (ceil (float (n - k) /. float (k - 1)) ))
