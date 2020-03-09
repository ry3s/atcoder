module Map = Map.Make (struct
                 type t = string
                 let compare = compare
               end)
let n = Scanf.scanf " %d" (fun x -> x)
let arr = Array.init n @@ fun _ -> Scanf.scanf " %s" (fun x -> x)
let () =
  let ans, _ =
    Array.fold_left
      (fun map v -> Map.add v (1 + try Map.find v map with _ -> 0) map)
      Map.empty arr
    |> (fun mp -> Map.fold
                     (fun k v (mk, mv) -> if v > mv then (k, v) else (mk, mv))
                     mp ("", 0)) in
  Printf.printf "%s\n" ans
