let () = Scanf.scanf "%d %d\n" @@ fun h w ->
  let ss = Array.init h ( fun _ ->  Array.init w (fun _ -> Scanf.scanf "%c" (fun x -> x))) in
  Array.init h (fun i -> 
    Array.to_list @@ Array.init w (fun j -> (i, j)))
  |> Array.to_list
  |> List.concat
  |> List.for_all (fun (i, j) ->
      ss.(i).(j) = '.' || 
        List.exists (fun (i, j) ->
          try ss.(i).(j) = '#' with _ -> false)
        [(i + 1, j); (i - 1, j); (i, j + 1); (i, j - 1) ])
  |> function
    | true -> print_endline "Yes"
    | false -> print_endline "No"
