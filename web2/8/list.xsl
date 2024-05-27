<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
      <head>
        <title>Music Files List</title>
        <style>
          .file-details {
          border: 1px solid #ddd;
          border-radius: 5px;
          padding: 10px;
          margin-bottom: 20px;
          display: flex;
          background-color: #f9f9f9; /* Цвет фона строк */
          }

          .file-details img {
          max-width: 100px;
          border: 1px solid #ddd;
          border-radius: 5px;
          }

          .file-details .info {
          margin-left: 20px;
          }

          .file-details .info p {
          margin: 0;
          margin-bottom: 10px;
          }

          .file-details .info p.title {
          font-size: 18px;
          font-weight: bold;
          text-transform: uppercase;
          }

          .file-details .info p.format {
          font-style: italic;
          }

          .file-details .info p.size {
          font-size: 14px;
          }

          .file-details .info a {
          text-decoration: none;
          background-color: #007bff; /* Цвет кнопки "Скачать" */
          color: #fff;
          padding: 8px 12px;
          border-radius: 5px;
          font-weight: bold;
          transition: background-color 0.3s ease; /* Плавное изменение цвета фона при наведении */
          }

          .file-details .info a:hover {
          background-color: #0056b3; /* Цвет кнопки "Скачать" при наведении */
          }

          .file-details .info .download-btn {
          margin-top: 10px;
          }


        </style>
      </head>
      <body>
        <h2>Список языков</h2>
        <xsl:apply-templates select="langs/lang"/>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="lang">
    <div class="file-details">
      <div class="info">
        <p class="title"><xsl:value-of select="title"/></p>
        <p><xsl:value-of select="description"/></p>
        <p><xsl:value-of select="creator"/></p>
        <p><xsl:value-of select="extension"/></p>
        <p><xsl:value-of select="mime"/></p>
        <p><xsl:value-of select="usage"/></p>
        <p><xsl:value-of select="latest_version"/></p>
      </div>
    </div>
  </xsl:template>
</xsl:stylesheet>
