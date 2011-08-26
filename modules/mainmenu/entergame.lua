function EnterGame_connectToLoginServer()
  local protocolLogin = ProtocolLogin.create()

  local recreateEnterGame = function()
    UI.loadAndDisplayLocked("/mainmenu/ui/entergamewindow.otui")
  end

  local loadBox = displayCancelBox("Please wait", "Connecting..")

  loadBox.onCancel = function(msgbox)
    -- cancel protocol and reacreate enter game window
    protocolLogin:cancelLogin()
    recreateEnterGame()
  end

  protocolLogin.onError = function(protocol, error)
    loadBox:destroy()
    local errorBox = displayErrorBox("Login Error", error)
    errorBox.onOk = recreateEnterGame
  end

  protocolLogin.onMotd = function(protocol, motd)
    loadBox:destroy()
    local motdNumber = string.sub(motd, 0, string.find(motd, "\n"))
    local motdText = string.sub(motd, string.find(motd, "\n") + 1, string.len(motd))
    if motdNumber ~= Configs.get("motd") then
      displayInfoBox("Message of the day", motdText)
      Configs.set("motd", motdNumber)
    end
    mainMenu:hide()
  end

  local enterGameWindow =  UI.root:getChildById("enterGameWindow")
  local account = enterGameWindow:getChildById("accountNameLineEdit"):getText()
  local password = enterGameWindow:getChildById("accountPasswordLineEdit"):getText()
  protocolLogin:login(account, password)

  enterGameWindow:destroy()
end
