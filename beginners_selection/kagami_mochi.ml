let () = Scanf.scanf "%d\n" (fun n ->
             Array.init n (fun _ -> Scanf.scanf " %d" (fun x -> x )))
         |> Array.to_list
         |> List.sort_uniq (-)
         |> List.length
         |> Printf.printf "%d\n"
              
              
    
