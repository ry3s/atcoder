let (n, d) = Scanf.scanf " %d %d" (fun x y -> (x, y))
let arr = List.init n (fun _ -> Scanf.scanf " %d %d" (fun x y -> (x, y)))

let () =
  let d = float (d * d) in
  arr
  |> List.filter (fun (x, y) ->
         (float x) ** 2. +. (float y) ** 2. <= d
       )
  |> List.length
  |> Printf.printf "%d\n"
