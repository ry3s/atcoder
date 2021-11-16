let () =
  let n, k = Scanf.scanf "%d %d" (fun x y -> (x, y)) in
  let rec loop i a =
    if i == k then a
    else
      let a_s = string_of_int a in
      let a_arr = Array.init (String.length a_s) (String.get a_s) in
      Array.sort compare a_arr;
      let g1 =
        Array.fold_right (fun x acc -> (acc * 10) + int_of_char x) a_arr 0
      in
      let g2 =
        Array.fold_left (fun acc x -> (acc * 10) + int_of_char x) 0 a_arr
      in
      loop (i + 1) (g1 - g2)
  in
  Printf.printf "%d\n" (loop 0 n)
