let rec take n l =
  match l with
  | [] -> []
  | x :: xs ->
     if n = 0 then []
     else x :: take (n-1) xs
let () =
  let n, m = Scanf.scanf "%d %d" (fun x y -> x, y) in
  let xyzs = Array.to_list @@ Array.init n (fun _ ->
      Scanf.scanf " %d %d %d"
        (fun x y z -> x, y, z)) in
  List.fold_left (fun (s1,s2,s3,s4,s5,s6,s7,s8) (x, y, z) ->
      ((x+y+z)::s1,
      (x+y-z)::s2,
      (x-y+z)::s3,
      (x-y-z)::s4,
      (-x+y+z)::s5,
      (-x+y-z)::s6,
      (-x-y+z)::s7,
      (-x-y-z)::s8)
    ) ([],[],[],[],[],[],[],[]) xyzs
  |> (fun (s1,s2,s3,s4,s5,s6,s7,s8) ->
    (List.fold_left (+) 0 @@ take  m @@ List.rev @@ List.sort compare s1) ::
    (List.fold_left (+) 0 @@ take  m @@ List.rev @@ List.sort compare s2) ::
    (List.fold_left (+) 0 @@ take  m @@ List.rev @@ List.sort compare s3) ::
    (List.fold_left (+) 0 @@ take  m @@ List.rev @@ List.sort compare s4) ::
    (List.fold_left (+) 0 @@ take  m @@ List.rev @@ List.sort compare s5) ::
    (List.fold_left (+) 0 @@ take  m @@ List.rev @@ List.sort compare s6) ::
    (List.fold_left (+) 0 @@ take  m @@ List.rev @@ List.sort compare s7) ::
    (List.fold_left (+) 0 @@ take  m @@ List.rev @@ List.sort compare s8) :: [])
|> List.fold_left max 0  
|>  Printf.printf "%d\n"
