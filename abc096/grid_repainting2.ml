let rec range a b = if a > b then [] else a :: range (a+1) b
let (>>=) x f = List.map f x |> List.concat

let () =
  let h, w = Scanf.scanf "%d %d\n" (fun h w -> h, w) in
  let ss = Array.init h (fun _ ->
               Scanf.scanf "%s\n" (fun x -> x)) in
             
  (range 0 (h-1) >>= fun i ->
   range 0 (w-1) >>= fun j -> [(i, j)])
  |> List.for_all (fun (i, j) ->
         ss.(i).[j] = '.'
         || List.exists (fun (x, y) ->
                try ss.(x).[y] = '#' with _ -> false)
              [(i-1, j); (i+1, j); (i, j-1); (i, j+1)])
  |> function
    | true -> print_endline "Yes"
    | false -> print_endline "No"
  

