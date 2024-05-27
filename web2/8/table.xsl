<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
      <head>
        <title>Таблица языков</title>
        <style>
          table, th, td {
            border: 1px solid black;
            border-collapse: collapse;
            padding: 8px;
          }
          th {
            background-color: #f2f2f2;
          }
        </style>
      </head>
      <body>
        <h2>Таблица языков</h2>
        <table>
          <tr>
            <th>Название</th>
            <th>Описание</th>
            <th>Создатель</th>
            <th>Расширение</th>
            <th>mime</th>
            <th>Где используется</th>
            <th>Последняя версия</th>
          </tr>
          <xsl:apply-templates select="langs/lang">
            <xsl:sort select="title"/>
          </xsl:apply-templates>
        </table>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="lang">
    <tr>
      <td><xsl:value-of select="title"/></td>
      <td><xsl:value-of select="description"/></td>
      <td><xsl:value-of select="creator"/></td>
      <td><xsl:value-of select="extension"/></td>
      <td><xsl:value-of select="mime"/></td>
      <td><xsl:value-of select="usage"/></td>
      <td><xsl:value-of select="latest_version"/></td>
    </tr>
  </xsl:template>
</xsl:stylesheet>
