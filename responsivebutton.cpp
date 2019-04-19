#include "responsivebutton.h"

void ResponsiveButton::myStateChanged() {
    emit iChanged(this);
}
