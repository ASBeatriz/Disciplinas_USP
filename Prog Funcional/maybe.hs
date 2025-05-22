import Data.Maybe

main = do
    putStrLn "opa"
    putStrLn $ show $ findElem 2 l
    putStrLn $ show $ findElem 3 l

    putStrLn $ show $ decodeMaybe $ findElem 2 l
    putStrLn $ show $ decodeMaybe $ findElem 3 l

l = [1, 2, 4, 5]

-- Maybe é uma forma de dar uma resposta e indicar que ela está num contexto que poderia falhar, 
-- além de padronizar o tipo que retorna (pra usar o elemento de just, é preciso desembrulhar)

findElem :: (Eq b) => b -> [b] -> Maybe b
findElem _ [] = Nothing
findElem a (x:xs) 
    | x == a = Just a
    | otherwise = findElem a xs

-- retorna o numero se ele existe, senão retorna -1
decodeMaybe :: Maybe Integer -> Integer
decodeMaybe (Just x) = x    -- desembrulha o maybe
decodeMaybe Nothing = -1
