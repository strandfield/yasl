// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

// QImage convertToFormat(QImage::Format, Qt::ImageConversionFlags) const;
QImage img_convertToFormat(const QImage & self, QImage::Format fmt, Qt::ImageConversionFlags cflags)
{
  return self.convertToFormat(fmt, cflags);
}

// QImage mirrored(bool, bool) const;
QImage img_mirrored(const QImage & self, bool horizontal, bool vertical)
{
  return self.mirrored(horizontal, vertical);
}

// QImage rgbSwapped() const;
QImage img_rgbSwapped(const QImage & self)
{
  return self.rgbSwapped();
}
