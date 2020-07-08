/*
 * Copyright (c) 2020 Valve Corporation
 * Copyright (c) 2020 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Authors:
 * - Richard S. Wright Jr. <richard@lunarg.com>
 * - Christophe Riccio <christophe@lunarg.com>
 */

#include "stringsettingwidget.h"

StringSettingWidget::StringSettingWidget(QTreeWidgetItem* pItem, LayerSettings* pLayerSetting) {
    layer_settings_ = pLayerSetting;
    pItem->setText(0, pLayerSetting->settings_prompt);
    pItem->setToolTip(0, pLayerSetting->settings_desc);
    this->setText(pLayerSetting->settings_value);
    connect(this, SIGNAL(textEdited(const QString&)), this, SLOT(itemEdited(const QString&)));
}

void StringSettingWidget::itemEdited(const QString& newString) {
    layer_settings_->settings_value = newString;
    emit itemChanged();
}
