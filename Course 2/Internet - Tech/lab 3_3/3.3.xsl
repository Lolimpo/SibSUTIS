<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<table border="1" style="">
		<tr bgcolor="#00FF00">
			<td> Название	</td>
			<xsl:for-each select="solar/planet">
        		<td align="center"><xsl:value-of select="@caption"/></td>
        	</xsl:for-each>
    	</tr>
    	<tr>
    		<td> Расстояние от солнца (a.e)	</td>
			<xsl:for-each select="solar/planet">
        		<td align="center"><xsl:value-of select="distance"/></td>
        	</xsl:for-each>
    	</tr>
    	<tr>
    		<td> Период обращения (г.)	</td>
			<xsl:for-each select="solar/planet">
        		<td align="center"><xsl:value-of select="circulation_period"/></td>
        	</xsl:for-each>
    	</tr>
    	<tr>
    		<td> Период вращения вокруг своей оси (ч.)</td>
			<xsl:for-each select="solar/planet">
        		<td align="center"><xsl:value-of select="revolution_period"/></td>
        	</xsl:for-each>
    	</tr>
    	<tr>
    		<td> Масса относительно Земли</td>
			<xsl:for-each select="solar/planet">
        		<td align="center"><xsl:value-of select="weight"/></td>
        	</xsl:for-each>
    	</tr>
    	<tr>
    		<td> Диаметр(км.)</td>
			<xsl:for-each select="solar/planet">
        		<td align="center"><xsl:value-of select="diametr"/></td>
        	</xsl:for-each>
    	</tr>
    	<tr>
    		<td>Количество спутников</td>
			<xsl:for-each select="solar/planet">
        		<td align="center"><xsl:value-of select="satellite_number"/></td>
        	</xsl:for-each>
    	</tr>
</table>

</xsl:template>
</xsl:stylesheet>