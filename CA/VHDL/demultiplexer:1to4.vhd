library IEEE;
use IEEE.STD_LOGIC_1164.all;
entity demux_1to4 is
 port(
 F : in STD_LOGIC;
 S0,S1: in STD_LOGIC;
 A,B,C,D: out STD_LOGIC
 );
end demux_1to4;
architecture bhv of demux_1to4 is
begin
process (F,S0,S1) is
begin
 if (S0 ='0' and S1 = '0') then
 A <= F;
B<=0;
C<=0;
D<=0;
 elsif (S0 ='1' and S1 = '0') then
 A<=0;
B <= F;
C<=0;
D<=0;
 elsif (S0 ='0' and S1 = '1') then
 A<=0;
B<=0;
C <= F;
D<=0;
 else
 A<=0;
B<=0;
C <= 0;
D <= F;
 end if;
end process;
end bhv;
