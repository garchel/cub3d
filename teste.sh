RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

echo "******************************** "testando 1.cub"  *********************************"
./cub3d 1.cub 
printf "${RED}ERRO${NC}\n"
printf "${YELLOW}um espaço entre todas as colunas${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando 2.cub"  *********************************"
./cub3d 2.cub
printf "${GREEN}OK${NC}\n"
printf "${YELLOW}mapa completamente normal${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando 3.cub"  *********************************"
./cub3d 3.cub
printf "${RED}ERRO${NC}\n"
printf "${YELLOW}numero inválido no mapa${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando 4.cub"  *********************************"
./cub3d 4.cub 
printf "${RED}ERRO${NC}\n"
printf "${YELLOW}faltando a parede de baixo${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando 5.cub"  *********************************"
./cub3d 5.cub
printf "${RED}ERRO${NC}\n"
printf "${YELLOW}faltando a parede da esquerda${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando 6.cub"  *********************************"
./cub3d 6.cub
printf "${GREEN}OK${NC}\n"
printf "${YELLOW}uma parede irregular${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando 7.cub"  *********************************"
./cub3d 7.cub 
printf "${RED}ERRO${NC}\n"
printf "${YELLOW}uma parede faltando na primeira linha${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando 8.cub"  *********************************"
./cub3d 8.cub
printf "${RED}ERRO${NC}\n"
printf "${YELLOW}uma parede faltando à direita${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando 9.cub"  *********************************"
./cub3d 9.cub
printf "${RED}ERRO${NC}\n"
printf "${YELLOW}faltando o char de inicio do personagem${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando 10.cub"  *********************************"
./cub3d 10.cub
printf "${RED}ERRO${NC}\n"
printf "${YELLOW}uma linha a mais no final do mapa${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando default.cub"  *********************************"
./cub3d default.cub
printf "${GREEN}OK${NC}\n"
printf "${YELLOW}mapa completamente irregular${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando empty.cub"  *********************************"
./cub3d empty.cub
printf "${RED}ERRO${NC}\n"
printf "${YELLOW}mapa vazio${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando library.cub"  *********************************"
./cub3d library.cub
printf "${GREEN}OK${NC}\n"
printf "${YELLOW}mapa normal${NC}\n"
echo "************************************************************************************"
echo "******************************** "testando not_real.cub"  *********************************"
./cub3d not_real.cub
printf "${RED}ERRO${NC}\n"
printf "${YELLOW}arquivo não existe${NC}\n"
echo "************************************************************************************"





