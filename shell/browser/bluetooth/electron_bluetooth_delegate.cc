// Copyright (c) 2020 Microsoft, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "shell/browser/bluetooth/electron_bluetooth_delegate.h"

#include <memory>
#include <utility>

#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "build/build_config.h"
#include "content/public/browser/render_frame_host.h"
#include "content/public/browser/web_contents.h"
#include "device/bluetooth/bluetooth_device.h"
#include "device/bluetooth/public/cpp/bluetooth_uuid.h"
#include "gin/converter.h"
#include "shell/browser/api/electron_api_session.h"
#include "shell/browser/api/electron_api_web_contents.h"
#include "shell/browser/lib/bluetooth_chooser.h"
#include "shell/common/gin_converters/callback_converter.h"
#include "shell/common/gin_converters/frame_converter.h"
#include "shell/common/gin_helper/dictionary.h"

#include "third_party/blink/public/common/bluetooth/web_bluetooth_device_id.h"
#include "third_party/blink/public/mojom/bluetooth/web_bluetooth.mojom.h"

using blink::WebBluetoothDeviceId;
using content::RenderFrameHost;
using content::WebContents;
using device::BluetoothUUID;

namespace gin {

template <>
struct Converter<content::BluetoothDelegate::PairingKind> {
  static v8::Local<v8::Value> ToV8(
      v8::Isolate* isolate,
      content::BluetoothDelegate::PairingKind paring_kind) {
    switch (paring_kind) {
      case content::BluetoothDelegate::PairingKind::kConfirmOnly:
        return StringToV8(isolate, "confirm");
      case content::BluetoothDelegate::PairingKind::kConfirmPinMatch:
        return StringToV8(isolate, "confirm_pin");
      case content::BluetoothDelegate::PairingKind::kProvidePin:
        return StringToV8(isolate, "provide_pin");
      default:
        return StringToV8(isolate, "unknown");
    }
  }
};

}  // namespace gin

namespace electron {

ElectronBluetoothDelegate::ElectronBluetoothDelegate() = default;

ElectronBluetoothDelegate::~ElectronBluetoothDelegate() = default;

std::unique_ptr<content::BluetoothChooser>
ElectronBluetoothDelegate::RunBluetoothChooser(
    content::RenderFrameHost* frame,
    const content::BluetoothChooser::EventHandler& event_handler) {
  auto* api_web_contents =
      api::WebContents::From(content::WebContents::FromRenderFrameHost(frame));
  return std::make_unique<BluetoothChooser>(api_web_contents, event_handler);
}

// The following methods are not currently called in Electron.
std::unique_ptr<content::BluetoothScanningPrompt>
ElectronBluetoothDelegate::ShowBluetoothScanningPrompt(
    content::RenderFrameHost* frame,
    const content::BluetoothScanningPrompt::EventHandler& event_handler) {
  LOG(INFO) << "In ElectronBluetoothDelegate::ShowBluetoothScanningPrompt";
  NOTIMPLEMENTED();
  return nullptr;
}

WebBluetoothDeviceId ElectronBluetoothDelegate::GetWebBluetoothDeviceId(
    RenderFrameHost* frame,
    const std::string& device_address) {
  LOG(INFO) << "In ElectronBluetoothDelegate::GetWebBluetoothDeviceId";
  NOTIMPLEMENTED();
  return WebBluetoothDeviceId::Create();
}

std::string ElectronBluetoothDelegate::GetDeviceAddress(
    RenderFrameHost* frame,
    const WebBluetoothDeviceId& device_id) {
  LOG(INFO) << "In ElectronBluetoothDelegate::GetDeviceAddress";
  NOTIMPLEMENTED();
  return nullptr;
}

WebBluetoothDeviceId ElectronBluetoothDelegate::AddScannedDevice(
    RenderFrameHost* frame,
    const std::string& device_address) {
  LOG(INFO) << "In ElectronBluetoothDelegate::AddScannedDevice";
  NOTIMPLEMENTED();
  return WebBluetoothDeviceId::Create();
}

WebBluetoothDeviceId ElectronBluetoothDelegate::GrantServiceAccessPermission(
    RenderFrameHost* frame,
    const device::BluetoothDevice* device,
    const blink::mojom::WebBluetoothRequestDeviceOptions* options) {
  LOG(INFO) << "In ElectronBluetoothDelegate::GrantServiceAccessPermission";
  NOTIMPLEMENTED();
  return WebBluetoothDeviceId::Create();
}

bool ElectronBluetoothDelegate::HasDevicePermission(
    RenderFrameHost* frame,
    const WebBluetoothDeviceId& device_id) {
  LOG(INFO) << "In ElectronBluetoothDelegate::HasDevicePermission";
  NOTIMPLEMENTED();
  return true;
}

void ElectronBluetoothDelegate::RevokeDevicePermissionWebInitiated(
    RenderFrameHost* frame,
    const WebBluetoothDeviceId& device_id) {
  LOG(INFO)
      << "In ElectronBluetoothDelegate::RevokeDevicePermissionWebInitiated";
  NOTIMPLEMENTED();
}

bool ElectronBluetoothDelegate::IsAllowedToAccessService(
    RenderFrameHost* frame,
    const WebBluetoothDeviceId& device_id,
    const BluetoothUUID& service) {
  NOTIMPLEMENTED();
  return true;
}

bool ElectronBluetoothDelegate::IsAllowedToAccessAtLeastOneService(
    RenderFrameHost* frame,
    const WebBluetoothDeviceId& device_id) {
  LOG(INFO)
      << "In ElectronBluetoothDelegate::IsAllowedToAccessAtLeastOneService";
  NOTIMPLEMENTED();
  return true;
}

bool ElectronBluetoothDelegate::IsAllowedToAccessManufacturerData(
    RenderFrameHost* frame,
    const WebBluetoothDeviceId& device_id,
    uint16_t manufacturer_code) {
  LOG(INFO)
      << "In ElectronBluetoothDelegate::IsAllowedToAccessManufacturerData";
  NOTIMPLEMENTED();
  return true;
}

void ElectronBluetoothDelegate::AddFramePermissionObserver(
    FramePermissionObserver* observer) {
  NOTIMPLEMENTED();
}

void ElectronBluetoothDelegate::RemoveFramePermissionObserver(
    FramePermissionObserver* observer) {
  NOTIMPLEMENTED();
}

std::vector<blink::mojom::WebBluetoothDevicePtr>
ElectronBluetoothDelegate::GetPermittedDevices(
    content::RenderFrameHost* frame) {
  std::vector<blink::mojom::WebBluetoothDevicePtr> permitted_devices;
  LOG(INFO) << "In ElectronBluetoothDelegate:::GetPermittedDevices";
  NOTIMPLEMENTED();
  return permitted_devices;
}

void ElectronBluetoothDelegate::ShowDevicePairPrompt(
    content::RenderFrameHost* frame,
    const std::u16string& device_identifier,
    PairPromptCallback callback,
    PairingKind pairing_kind,
    const absl::optional<std::u16string>& pin) {
  LOG(INFO) << "In ElectronBluetoothDelegate::ShowDevicePairPrompt";
  pair_prompt_callback_ = std::move(callback);

  bool prevent_default = false;

  auto* web_contents = content::WebContents::FromRenderFrameHost(frame);
  if (web_contents) {
    LOG(INFO) << "In ElectronBluetoothDelegate::ShowDevicePairPrompt, got web "
                 "contents; now get session";
    api::Session* session =
        api::Session::FromBrowserContext(web_contents->GetBrowserContext());
    v8::Isolate* isolate = JavascriptEnvironment::GetIsolate();
    v8::HandleScope scope(isolate);
    gin_helper::Dictionary details =
        gin_helper::Dictionary::CreateEmpty(isolate);
    details.Set("deviceId", device_identifier);
    details.Set("pairing_kind", pairing_kind);
    details.SetGetter("frame", frame);
    if (pin.has_value()) {
      details.Set("pin", pin.value());
    }
    LOG(INFO) << "In ElectronBluetoothDelegate::ShowDevicePairPrompt, emitting "
                 "'bluetooth-pair-prompt'";
    prevent_default = session->Emit(
        "bluetooth-pair-prompt", details,
        base::AdaptCallbackForRepeating(base::BindOnce(
            &ElectronBluetoothDelegate::OnDevicePairPromptResponse,
            weak_factory_.GetWeakPtr())));

    if (!prevent_default) {
      LOG(INFO) << "In ElectronBluetoothDelegate::ShowDevicePairPrompt, "
                   "prevent_default is false so cancel the pair prompt";
      std::move(pair_prompt_callback_)
          .Run(BluetoothDelegate::PairPromptResult(
              BluetoothDelegate::PairPromptStatus::kCancelled));
    }
  }
}

void ElectronBluetoothDelegate::OnDevicePairPromptResponse(
    gin::Arguments* args) {
  BluetoothDelegate::PairPromptResult result;
  LOG(INFO) << "In ElectronBluetoothDelegate::OnDevicePairPromptResponse(, "
               "prevent_default is false so cancel the pair prompt";
  bool confirmed;
  std::u16string pin;
  if (args->GetNext(&confirmed) && confirmed) {
    result.result_code = BluetoothDelegate::PairPromptStatus::kSuccess;
  } else {
    result.result_code = BluetoothDelegate::PairPromptStatus::kCancelled;
  }
  if (args->GetNext(&pin) && !pin.empty()) {
    std::u16string trimmed_input;
    base::TrimWhitespace(pin, base::TRIM_ALL, &trimmed_input);
    result.pin = base::UTF16ToUTF8(trimmed_input);
  }
  std::move(pair_prompt_callback_).Run(result);
}

}  // namespace electron
