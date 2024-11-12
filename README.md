Demo des libraries graphiques utilisable durant le tronc commun de 42

# Makefile
## build project
```
make
```
Ça va télécharger les libs, les compiler et compiler les mains
## download libs
```
make setuplibs
```
Pour seulement télécharger les libs
## remove executable
```
make clean
```
Pour supprimer seulement les éxécutables
## remove libs
```
make cleanlibs
```
Pour supprimer seulement les libs
```
make fclean
```
Pour supprimer les libs et les éxécutables
# Executable
Une fois compiler, il y a 3 éxécutables :
- minilibx : exe avec la minilibx
- macrolibx : exe avec la macrolibx
- codam : exe avec la mlx de codam
# Leak
## Minilibx
Pas de leak
## Macrolibx
Leak, possède déjà un vsupp (Macrolibx/valgrind.supp) mais il reste quand même des leaks
## mlx42 - codam
Leak aussi.
