-- import Data.List
import qualified Data.List as DL
import Data.Maybe (fromMaybe) -- importando só uma função de Data.Maybe (nesse caso "formMaybe")

main = do
    putStrLn $ show $ sum $ Main.map (^2) $ filter ((== 1).(`mod` 2)) a  -- funções próprias
    putStrLn $ show $ take 5 $ Main.map (^2) a  
    putStrLn $ show $ DL.nub a -- elementos não repetidos (aqui o DL. só seria necessário para não haver conflito com outras funções de outras bibliotecas)

a = [1, 2, 3, 4, 5, 1, 2, 3, 6, 4, 7]

-- se for usar o mesmo nome, referenciar de onde voce quer a funão, mas não é recomendado 
map _ [] = []
map f (x:xs) = f x: Main.map f xs